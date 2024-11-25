import os
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
import datetime
from imageStyleTransfer.settings import MEDIA_ROOT, MEDIA_URL
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
            # 调用图像处理函数
            processed_file_url = image_process_Canny(save_path)
            # 返回处理后的文件 URL
            return JsonResponse({'processed_file_url': processed_file_url})
        else:
            return JsonResponse({'error': 'No file uploaded'}, status=400)
    return JsonResponse({'error': 'Invalid request method'}, status=405)

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