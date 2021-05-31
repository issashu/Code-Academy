# def multiply (a,b):
 #   """
 #   >>> multiply (10,20)
 #   200
 #   >>> multiply ('b', 5)
 #   'bbbbb'
 #   >>> multiply (2,3)
 #   10
 #   """
#  return a*b

import unittest
import inspect

class TestClass (unittest.TestCase):
    def test_case02(self):
        print("\n Running test method:" +inspect.stack()[0][3])
    
    def test_case01(self):
        print("\n Running test method:" +inspect.stack()[0][3])

if __name__ == "__main__":
    unittest.main()