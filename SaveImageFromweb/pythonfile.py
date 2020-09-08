import requests
import os
import subprocess
import urllib.request
from bs4 import BeautifulSoup
import tldextract
broken_images = []
image_urls = ['https://sempioneer.com/wp-content/uploads/2020/05/dataframe-300x84.png',
             'https://sempioneer.com/wp-content/uploads/2020/05/json_format_data-300x72.png']
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