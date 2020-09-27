# AliExpress Parser

This script is designed to collect information from AliExpress.

You will get the following data:
- Product Title
- Product Category
- Regular Price
- Discount Price
- Options
- Item Specifics
- Packaging Details
- Images URL
- Product URL

## How to use

Go to scrapy_aliexpress/spiders/ali.py and replace link in start_urls

Run the script:

```
scrapy crawl ali -o ali.csv -t csv
```

## Requirements

- Python 3
- Scrapy
