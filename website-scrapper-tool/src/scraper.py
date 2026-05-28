import requests
from bs4 import BeautifulSoup

class WebsiteScraper:
    def __init__(self, base_url):
        self.base_url = base_url
        self.session = requests.Session()

    def fetch_page(self, endpoint="/"):
        url = f"{self.base_url}{endpoint}"
        response = self.session.get(url)
        response.raise_for_status()
        return response.text

    def extract_links(self, html):
        soup = BeautifulSoup(html, "html.parser")
        links = []
        for a_tag in soup.find_all("a", href=True):
            href = a_tag["href"]
            if href.startswith("http"):
                links.append(href)
        return links

    def scrape_links(self, endpoint="/"):
        html = self.fetch_page(endpoint)
        return self.extract_links(html)