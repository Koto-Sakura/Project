from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.

def index(request):
    return render(request, 'index.html')
def nothing(request):
    return HttpResponse("Nothing to see here,you should go to /index")