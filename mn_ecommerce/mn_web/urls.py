from django.urls import path
from . import views

app_name = 'mn_web'

urlpatterns = [
    path('', views.HomeView.as_view(), name='index'),
]
