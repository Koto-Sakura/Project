from django.contrib import admin
from django.urls import path
from ImageST import views
urlpatterns = [
    path('admin/', admin.site.urls),
    path('index/', views.index, name='index'),
    path('',views.nothing, name='nothing')
]
