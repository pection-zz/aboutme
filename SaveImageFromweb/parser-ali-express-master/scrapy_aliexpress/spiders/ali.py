from scrapy.spiders import Spider
from scrapy.http import Request
from scrapy_aliexpress.items import ScrapyAliexpressItem


class AliSpider(Spider):
    """ Spider for aliexpress.com """
    name = 'ali'
    allowed_domains = ['aliexpress.com', 'www.aliexpress.com']
    start_urls = ['https://www.aliexpress.com/store/'
                  'all-wholesale-products/1084571.html']

    def parse(self, response):
        product_urls = response\
            .xpath('//ul[contains(@class, "items-list")]//h3/a/@href')\
            .extract()
        for product_url in product_urls:
            item = ScrapyAliexpressItem()
            product_page = Request(product_url, callback=self.product_data)
            product_page.meta['item'] = item
            yield product_page
            if item:
                yield item

        next_page = 'http:' + response.css('a.ui-pager-next::attr(href)')\
            .extract_first()
        if next_page is not None:
            next_page = response.urljoin(next_page)
            yield Request(next_page, callback=self.parse)

    def product_data(self, response):
        """ Return product details """
        item = response.meta['item']
        item['title'] = response.css('h1.product-name::text').extract()
        item['product_url'] = response.url
        item['category'] = response.css('div.breadcrumb-layout b::text')\
            .extract()

        # get regular price
        reg_price = response\
            .xpath('//span[contains(@id, "j-sku-price")]//text()')\
            .extract()
        item['regular_price'] = self.new_price(reg_price)

        # get discount price
        discount_price = response\
            .xpath('//span[contains(@id, "j-sku-discount-price")]//text()')\
            .extract()
        if discount_price is not None:
            item['discount_price'] = self.new_price(discount_price)
        else:
            item['discount_price'] = ''

        # get options
        options1 = response.xpath('//ul[contains (@id, "j-sku-list-1")]'
                                  '//a/@title').extract()
        options2 = response.xpath('//ul[contains (@id, "j-sku-list-2")]'
                                  '//a//span/text()').extract()
        item['options1'] = options1
        item['options2'] = options2

        # get item specifics
        item_specifics = response\
            .xpath('//div[contains(@id, "j-product-desc")]'
                   '//li[contains(@class, "property-item")]'
                   '//text()').extract()
        item['item_specifics'] = self.string_details(item_specifics)

        # get package details
        package_details = response\
            .xpath('//div[contains(@id, "j-product-desc")]'
                   '//li[contains(@class, "packaging-item")]'
                   '//text()').extract()
        item['packaging_details'] = self.string_details(package_details)

        # get images urls
        images_urls = response\
            .xpath('//ul[contains(@id, "j-image-thumb-list")]'
                   '//li//img//@src').extract()
        item['images_url'] = self.get_images(images_urls)
        return item

    def get_images(self, images_urls):
        """ Returns links to images as string """
        image_links = ''
        for image in images_urls:
            image_link = image.split('jpg')
            image_link2 = image_link[0] + 'jpg\n'
            image_links += image_link2
        return image_links

    def string_details(self, details):
        """ Return item spesifics and package details as string """
        if isinstance(details, list):
            specs = ''
            for spec in details:
                if '\n' in spec:
                    spec = ''
                if spec:
                    if ':' in spec:
                        spec += ' '
                    else:
                        spec += '\n'
                specs += spec
            return specs
        else:
            return details

    def new_price(self, prices):
        """ Return price as string """
        if isinstance(prices, list):
            n_price = ''
            for price in prices:
                n_price += price
            return n_price
        else:
            return price
