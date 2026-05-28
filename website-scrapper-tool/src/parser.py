from urllib.parse import urlparse

class LinkParser:
    @staticmethod
    def filter_domain(links, domain):
        return [link for link in links if domain in urlparse(link).netloc]

    @staticmethod
    def get_domain(link):
        parsed = urlparse(link)
        return parsed.netloc

    @staticmethod
    def is_valid_url(link):
        parsed = urlparse(link)
        return all([parsed.scheme, parsed.netloc])