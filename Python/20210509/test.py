import unittest

def setUpModule():
    print("In setup Module...")

def tearDownModule():
    print("In teardown module...")

class testClass(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print ("In setup class...")
    
    @classmethod
    def tearDownClass(cls):
        print ("In teardoewn class...")
    
    def setUp(self):
        print("In self setup...")
    
    def tearDown(self):
        print("In self tear down...")
    
    def test_case01(self):
        self.assertTrue("CODEACADEMY".isupper())
        print ("In test case 01")
    
    def test_case02(self):
        self.assertTrue("codeacademy".isupper())
        print("In test case 02")
    
if __name__ == '__main__':
    unittest.main()
    
