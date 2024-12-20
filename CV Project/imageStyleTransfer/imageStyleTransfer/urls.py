from django.contrib import admin
from django.urls import path
from ImageST import views
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    path('admin/', admin.site.urls),
    path('index/', views.index, name='index'),
    path('transfer/', views.transfer, name='transfer'),
    path('save/', views.save_image, name='save'),
    path('', views.index, name='index')
]+ static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
