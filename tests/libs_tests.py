from unittest import TestCase
from ctypes import *


path_so = './output-files/libs-so/libcalculadora.so'


def check_so(so_lib):
    try:
        lib = CDLL(so_lib)
        return lib
    except OSError as ex:
        print("WARNING:", ex)
        return None

class TestCalculadora(TestCase):

    def setUp(self):
        super(TestCalculadora, self).setUp()
        self.lib = check_so(path_so)

    def testSoma(self):
        self.assertEqual(self.lib.soma(3, 3), 6)

    def testDivisao(self):
        self.assertEqual(self.lib.divisao(3, 3), 1)

    def testSubtracao(self):
        self.assertEqual(self.lib.subtracao(3, 3), 0)

    def testProduto(self):
        self.assertEqual(self.lib.produto(3, 3), 9)
