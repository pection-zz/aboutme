import requests
import os
import subprocess
import urllib.request
from bs4 import BeautifulSoup
import tldextract
broken_images = []
import argparse

ap = argparse.ArgumentParser()
ap.add_argument("-u", "--url", type=str,
  help="url to save image")
args = vars(ap.parse_args())
if args["url"] !=False:
    image_urls=[args["url"]]
else
    image_urls = ['https://5krorwxhkqjiiij.ldycdn.com/cloud/irBqkKkqRilSjqkrnjko/SF-1-56-FT-28-HMC-L.jpg']
for img in image_urls:
    # We can split the file based upon / and extract the last split within the python list below:
    file_name = img.split('/')[-1]
    print(f"This is the file name: {file_name}")
    # Now let's send a request to the image URL:
    r = requests.get(img, stream=True)
    # We can check that the status code is 200 before doing anything else:
    if r.status_code == 200:
        # This command below will allow us to write the data to a file as binary:
        with open(file_name, 'wb') as f:
            for chunk in r:
                f.write(chunk)
    else:
        # We will write all of the images back to the broken_images list:
        broken_images.append(img)