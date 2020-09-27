import requests
import json
import re

target = ["title", "itemDetailUrl", "imagePath"]


def main(url):
    r = requests.get(url)
    match = re.search(r'data: ({.+})', r.text).group(1)
    data = json.loads(match)
    goal = [data['pageModule'][x] for x in target] + \
        [data['priceModule']['formatedActivityPrice']]
    print(goal)


main("https://es.aliexpress.com/item/32601027783.html")