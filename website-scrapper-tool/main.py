from src.scraper import WebsiteScraper
from src.parser import LinkParser
import sys

def main():
    if len(sys.argv) < 2:
        print("Usage: python main.py <url>")
        sys.exit(1)

    url = sys.argv[1]
    scraper = WebsiteScraper(url)
    parser = LinkParser()

    try:
        links = scraper.scrape_links()
        print(f"Found {len(links)} links:")

        for link in links[:10]:
            print(f"  - {link}")

        domain_links = parser.filter_domain(links, urlparse(url).netloc)
        print(f"\nInternal links: {len(domain_links)}")

    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()