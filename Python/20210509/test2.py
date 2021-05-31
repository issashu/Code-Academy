import unittest

class TestClass2(unittest.TestCase):
    def test_case01(self):
        print(self.id())
        print(self.shortDescription())
        self.fail()


if __name__ == '__main__':
    unittest.main()

