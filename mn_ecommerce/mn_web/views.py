from django.shortcuts import render
from django.views.generic import ListView, CreateView, UpdateView,View
# from django.core.urlresolvers import reverse
# from contacts.models import Contact
# import forms
# Create your views here.
import random
import string
import stripe

from django.http import HttpResponse


def index(request):
    return HttpResponse("Hello, world. You're at the polls index.")
class HomeView(View):
    template_name = "index.html"
