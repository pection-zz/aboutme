
import selenium
selenium.__file__
from selenium import webdriver


# This is the path I use
# DRIVER_PATH = '.../Desktop/Scraping/chromedriver 2'
# Put the path for your ChromeDriver here
DRIVER_PATH = '/Users/pection/Programing/SaveImage/chromedriver'
# driver.get("http://www.python.org")
wd = webdriver.Chrome(executable_path=DRIVER_PATH)
