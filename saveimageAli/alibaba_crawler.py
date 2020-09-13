import scrapy


class AlibabaCrawlerSpider(scrapy.Spider):
    name = 'alibaba_crawler'
    allowed_domains = ['alibaba.com']
    start_urls = ['http://alibaba.com/']

    def parse(self, response):
        pass
