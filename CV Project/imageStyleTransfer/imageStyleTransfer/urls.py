from django.contrib import admin
from django.urls import path
from ImageST import views
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    path('admin/', admin.site.urls),
    path('index/', views.index, name='index'),
    path('transfer/', views.transfer, name='transfer'),
    # path('convert/', views.convert_grayscale, name='convert'),
    path('save/', views.save_image, name='save'),
    # path('download/<str:filename>/', views.download_image, name='download'),
    path('', views.nothing, name='nothing')
]+ static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
