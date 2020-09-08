
# import selenium
# selenium.__file__
from selenium import webdriver
from selenium.webdriver.common.by import By

elem=[]
# This is the path I use
# DRIVER_PATH = '.../Desktop/Scraping/chromedriver 2'
# Put the path for your ChromeDriver here
DRIVER_PATH = '/Users/pection/Programing/SaveImage/chromedriver'
# driver.get("http://www.python.org")
driver = webdriver.Chrome(executable_path=DRIVER_PATH)
# assert "Python" in driver.title
# driver.implicitly_wait(10)

driver.get("https://zztrade.en.alibaba.com/productgrouplist-820683175/LC_09.html?spm=a2700.icbuShop.88.48.21387404xVfVlO")#put here the adress of your page

driver.implicitly_wait(10)

content = driver.find_elements(By.CSS_SELECTOR,("a.product-image"))
# for i in browser.find_elements_by_xpath("//*[@type='submit']"):
#     print (i.get_attribute("value"))

# button = driver.find_element_by_id('buttonID')
print(content)
driver.close()
