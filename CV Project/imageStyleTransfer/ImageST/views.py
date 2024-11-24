import os
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
from django.core.files.storage import FileSystemStorage
import datetime
from imageStyleTransfer.settings import MEDIA_ROOT,MEDIA_URL

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
            print(save_path+','+new_filename)
            with open(save_path, 'wb+') as destination:
                for chunk in image.chunks():
                    destination.write(chunk)
            # 返回保存的文件 URL
            return JsonResponse({'uploaded_file_url': f'{MEDIA_URL}imgs/{new_filename}'})
        else:
            return JsonResponse({'error': 'No file uploaded'}, status=400)
    return JsonResponse({'error': 'Invalid request method'}, status=405)

