# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class ScrapyAliexpressItem(scrapy.Item):
    title = scrapy.Field()
    category = scrapy.Field()
    regular_price = scrapy.Field()
    discount_price = scrapy.Field()
    options1 = scrapy.Field()
    options2 = scrapy.Field()
    item_specifics = scrapy.Field()
    packaging_details = scrapy.Field()
    images_url = scrapy.Field()
    product_url = scrapy.Field()
