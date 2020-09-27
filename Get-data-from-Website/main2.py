from selenium import webdriver
import chromedriver_binary  # Adds chromedriver binary to path

driver = webdriver.Chrome()
driver.get("https://oulunmei.en.alibaba.com/it_IT/productgrouplist-818789095/Tabella_di_preparazione.html?spm=a2700.icbuShop.98.5.30023686ZPFxuv")
time.sleep(5)

seq_query_field = driver.find_element_by_class("icbu-pc-images magic-0")
seq_query_field.send_keys(SEQUENCE)
blast_button = driver.find_element_by_id("b1")
blast_button.click()

time.sleep(60)
content = driver.page_source

with open('webpage.html', 'w') as f:

    f.write(content)