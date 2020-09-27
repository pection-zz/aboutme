import bs4
import requests
from fake_useragent import UserAgent
import csv

## create an array with URLs
urls = ['/Users/pection/Documents/ProductList/oulunmei.en.alibaba.com/productgrouplist-818789095/Dressing_Table_Chair_scene=all&language=english.html']

## initializing the UserAgent object
user_agent = UserAgent()

## starting the loop
for url in urls:
    ## getting the reponse from the page using get method of requests module
    page = requests.get(url, headers={"user-agent": user_agent.chrome})

    ## storing the content of the page in a variable
    html = page.content

    ## creating BeautifulSoup object
    soup = bs4.BeautifulSoup(html, "html.parser")