import os
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
import datetime
import numpy as np
from imageStyleTransfer.settings import MEDIA_ROOT, MEDIA_URL,STATICFILES_DIRS
import cv2

def index(request):
    return render(request, 'index.html')

def nothing(request):
    return HttpResponse("Nothing to see here, you should go to /index")

def transfer(request):
    return render(request, 'transfer.html')

def save_image(request):
    print("saving...")
    if request.method == 'POST':
        if 'image-input' in request.FILES:
            image = request.FILES['image-input']
            # 获取当前时间并格式化
            current_time = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
            # 生成新的文件名
            new_filename = f"{current_time}-source.{image.name.split('.')[-1]}"
            # 指定保存路径
            save_path = os.path.join(MEDIA_ROOT, 'imgs', new_filename)
            print(save_path + ',' + new_filename)
            with open(save_path, 'wb+') as destination:
                for chunk in image.chunks():
                    destination.write(chunk)
            # 获取用户选择的风格
            style_type = request.POST.get('style-select', 'retro')  # 默认选择怀旧风
            print(f"Selected style: {style_type}")
            # 调用图像处理函数
            if style_type == 'retro':
                processed_file_url = apply_retro_style(save_path)
            elif style_type == 'pixel':
                processed_file_url = apply_pixel_style(save_path)
            elif style_type =='sketch':
                processed_file_url = apply_sketch_style(save_path)
            else:
                return JsonResponse({'error': 'Invalid style selected'}, status=400)
            # 调用图像处理函数
                # processed_file_url = image_process_Canny(save_path)
            # 返回处理后的文件 URL
            return JsonResponse({'processed_file_url': processed_file_url})
        else:
            return JsonResponse({'error': 'No file uploaded'}, status=400)
    return JsonResponse({'error': 'Invalid request method'}, status=405)

def apply_retro_style(image_path):#怀旧化
    # 生成处理后的文件名
    print("this is retro style")
    current_time = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    result_filename = f"{current_time}-vintage-result.{image_path.split('.')[-1]}"
    result_save_path = os.path.join(MEDIA_ROOT, 'imgs', result_filename)
    
    # 处理图片
    img = cv2.imread(image_path)
    result_img = img.copy()
    h, w, n = img.shape
    for i in range(w):
        for j in range(h):
            b = img[j, i, 0]
            g = img[j, i, 1]
            r = img[j, i, 2]
            B = int(0.272 * r + 0.534 * g + 0.131 * b)
            G = int(0.349 * r + 0.686 * g + 0.168 * b)
            R = int(0.393 * r + 0.769 * g + 0.189 * b)
            result_img[j, i, 0] = max(0, min(B, 255))
            result_img[j, i, 1] = max(0, min(G, 255))
            result_img[j, i, 2] = max(0, min(R, 255))
    # 保存处理后的图像
    cv2.imwrite(result_save_path, result_img)
    
    return result_save_path

def apply_pixel_style(image_path):#像素化
    # 生成处理后的文件名
    print("this is pixel style")
    current_time = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    result_filename = f"{current_time}-comic-result.{image_path.split('.')[-1]}"
    result_save_path = os.path.join(MEDIA_ROOT, 'imgs', result_filename)
    # 处理图片
    img = cv2.imread(image_path)
    # 马赛克化
    alpha = 0.15#缩放比例，较小的值会使效果更明显
    h,w,ch=img.shape
    img=cv2.resize(img,(int(w*alpha), int(h*alpha)))
    img=cv2.resize(img,(w,h),interpolation=cv2.INTER_NEAREST)
    # 减少颜色
    Z=img.reshape((-1,3))
    z=np.float32(Z)
    criteria=(cv2.TERM_CRITERIA_EPS+cv2.TERM_CRITERIA_MAX_ITER,10,1.0)
    
    K=12#颜色数量，越大效果越明显，增加计算量
    
    ret,label,center=cv2.kmeans(z,K,None,criteria,10,cv2.KMEANS_RANDOM_CENTERS)
    center=np.uint8(center)
    res=center[label.flatten()]
    result=res.reshape((img.shape))
    cv2.imwrite(result_save_path, result)
    # 返回处理后的文件 URL
    return f'{MEDIA_URL}imgs/{result_filename}'
from django.contrib.staticfiles.storage import staticfiles_storage
import os
import cv2
import numpy as np
from imageStyleTransfer.settings import MEDIA_ROOT, MEDIA_URL

def apply_sketch_style(image_path):  # 素描化
    # 生成处理后的文件名
    print("this is sketch style")
    current_time = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    result_filename = f"{current_time}-comic-result.{image_path.split('.')[-1]}"
    result_save_path = os.path.join(MEDIA_ROOT, 'imgs', result_filename)
    
    # 处理图片
    img = cv2.imread(image_path)
    if img is None:
        print(f"Failed to load input image: {image_path}")
        return None
    
    # 获取 screen-2.png 
    screen = cv2.imread(os.path.join(STATICFILES_DIRS[0], 'imgs', 'screen.jpg'))
    # 转换为灰度图像
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    screen_gray = cv2.cvtColor(screen, cv2.COLOR_BGR2GRAY)
    screen_gray = cv2.resize(screen_gray, (img_gray.shape[1], img_gray.shape[0]))
    
    # 边缘检测
    edge = 255 - cv2.Canny(img_gray, 80, 200)
    
    # 三值化
    th1 = 80
    th2 = 110  # th1, th2为阈值
    img_gray[img_gray <= th1] = 0
    img_gray[img_gray > th2] = 255
    img_gray[np.where((img_gray > th1) & (img_gray < th2))] = screen_gray[np.where((img_gray > th1) & (img_gray < th2))]
    
    # 合成结果
    result = cv2.bitwise_and(img_gray, edge)
    cv2.imwrite(result_save_path, result)
    
    # 返回处理后的文件 URL
    return f'{MEDIA_URL}imgs/{result_filename}'
def image_process_Canny(image_path):
    # 生成处理后的文件名
    current_time = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    result_filename = f"{current_time}-result.{image_path.split('.')[-1]}"
    result_save_path = os.path.join(MEDIA_ROOT, 'imgs', result_filename)
    
    # 处理图片
    img = cv2.imread(image_path)
    edges = cv2.Canny(img, 100, 200)
    cv2.imwrite(result_save_path, edges)
    
    # 返回处理后的文件 URL
    return f'{MEDIA_URL}imgs/{result_filename}'