import unittest
from Projekt import Graf
from Projekt import Wezel
from Projekt import Krawedz


class TestGraf(unittest.TestCase):
    def setUp(self):
        """Przygotowanie nowego grafu dla każdego testu."""
        self.graf = Graf()

    def test_dodawanie_wezlow(self):
        """Testuje, czy można dodawać węzły do grafu."""
        self.graf.dodaj_wezel("A")
        self.graf.dodaj_wezel("B")

        self.assertIn("A", self.graf.wezly)
        self.assertIn("B", self.graf.wezly)
        self.assertEqual(len(self.graf.wezly), 2)

    def test_dfs_przeplyw(self):
        """Testuje przepływ przez ścieżki w grafie."""
        self.graf.dodaj_krawedz("A", "B", 10)
        self.graf.dodaj_krawedz("B", "C", 5)

        zrodlo = self.graf.wezly["A"]
        cel = self.graf.wezly["C"]

        przeplyw = self.graf.dfs(zrodlo, cel, float('inf'), set())
        self.assertEqual(przeplyw, 5)

    def test_ford_fulkerson(self):
        """Testuje maksymalny przepływ za pomocą algorytmu Forda-Fulkersona."""
        self.graf.dodaj_krawedz("A", "B", 10)
        self.graf.dodaj_krawedz("B", "C", 5)

        zrodlo = self.graf.wezly["A"]
        cel = self.graf.wezly["C"]

        maksymalny_przeplyw = self.graf.ford_fulkerson(zrodlo, cel)
        self.assertEqual(maksymalny_przeplyw, 5)

    def test_maksymalny_przeplyw(self):
        graf = Graf()
        graf.dodaj_krawedz("A", "B", 11)
        graf.dodaj_krawedz("A", "C", 19)
        graf.dodaj_krawedz("B", "D", 1)
        graf.dodaj_krawedz("C", "D", 10)
        graf.dodaj_krawedz("C", "E", 25)
        graf.dodaj_krawedz("D", "F", 15)
        graf.dodaj_krawedz("E", "F", 17)
        graf.dodaj_krawedz("F", "G", 12)
        graf.dodaj_krawedz("D", "G", 9)
        graf.dodaj_krawedz("E", "G", 8)

        zrodlo = graf.wezly["A"]
        cel = graf.wezly["G"]

        maksymalny_przeplyw = self.graf.ford_fulkerson(zrodlo, cel)
        
        self.assertEqual(maksymalny_przeplyw, 20)
if __name__ == "__main__":
    unittest.main()
