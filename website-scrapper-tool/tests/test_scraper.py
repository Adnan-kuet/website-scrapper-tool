import pytest
from src.scraper import WebsiteScraper
from src.parser import LinkParser

def test_scraper_initialization():
    scraper = WebsiteScraper("https://example.com")
    assert scraper.base_url == "https://example.com"

def test_parser_filter_domain():
    parser = LinkParser()
    links = [
        "https://example.com/page1",
        "https://other.com/page2",
        "https://example.com/page3"
    ]
    filtered = parser.filter_domain(links, "example.com")
    assert len(filtered) == 2
    assert "https://other.com/page2" not in filtered

def test_parser_get_domain():
    parser = LinkParser()
    domain = parser.get_domain("https://www.example.com/path?q=1")
    assert domain == "www.example.com"

def test_parser_is_valid_url():
    parser = LinkParser()
    assert parser.is_valid_url("https://example.com") == True
    assert parser.is_valid_url("not-a-url") == False