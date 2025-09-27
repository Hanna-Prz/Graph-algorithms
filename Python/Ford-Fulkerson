class Krawedz:
    def __init__(self, przepustowosc, start_wezel, end_wezel):
        self.przepustowosc = przepustowosc  # Maksymalny przepływ przez krawędź
        self.start_wezel = start_wezel      # Węzeł początkowy
        self.end_wezel = end_wezel          # Węzeł końcowy
        self.przepustowosc_odwrotna = 0     # Przepustowość odwrotna krawędzi (do przepływu odwrotnego)

    def zmien_przepustowosc_odwrotna(self, liczba):
        """Aktualizuje przepustowość odwrotną krawędzi."""
        self.przepustowosc_odwrotna += liczba

    def czy_krawedz_jest_max_uzyta(self):
        """Sprawdza, czy krawędź jest już w pełni wykorzystana (przepustowność == przepustowosc_odwrotna)."""
        return self.przepustowosc == self.przepustowosc_odwrotna


class Wezel:
    def __init__(self, nazwa):
        self.nazwa = nazwa        # Nazwa węzła (unikalna)
        self.krawedzie = []       # Lista wychodzących krawędzi

    def dodaj_krawedz(self, krawedz):
        """
        Dodaje krawędź do listy krawędzi wychodzących z tego węzła.
        """
        self.krawedzie.append(krawedz)


class Graf:
    def __init__(self):
        self.wezly = {}        # Słownik węzłów (klucz: nazwa węzła, wartość: obiekt Wezel)
    def dodaj_wezel(self, nazwa):
        """
        Dodaje nowy węzeł do grafu.
        """
        if nazwa not in self.wezly:
            self.wezly[nazwa] = Wezel(nazwa)
        return self.wezly[nazwa]

    def dodaj_krawedz(self, nazwa_start, nazwa_koniec, przepustowosc):
        """
        Dodaje krawędź do grafu między dwoma węzłami.
        """
        start_wezel = self.dodaj_wezel(nazwa_start)
        end_wezel = self.dodaj_wezel(nazwa_koniec)

        krawedz = Krawedz(przepustowosc, start_wezel, end_wezel)
       

        start_wezel.dodaj_krawedz(krawedz)

    def dfs(self, wezel, cel, przeplyw, odwiedzone):
        """
        Algorytm DFS do znajdowania ścieżek powiększających przepływ.
        """
        if wezel == cel:
            return przeplyw

        odwiedzone.add(wezel)

        for krawedz in wezel.krawedzie:
            # Sprawdzamy dostępność przepływu w tej krawędzi
            if krawedz.end_wezel not in odwiedzone and krawedz.przepustowosc > krawedz.przepustowosc_odwrotna:
                dostepny_przeplyw = krawedz.przepustowosc - krawedz.przepustowosc_odwrotna
                # Przeszukujemy dalej
                wynik = self.dfs(krawedz.end_wezel, cel, min(przeplyw, dostepny_przeplyw), odwiedzone)
                
                if wynik > 0:
                    # Aktualizujemy przepustowość wzdłuż ścieżki
                    krawedz.przepustowosc_odwrotna += wynik
                    
                    return wynik

        return 0

    def ford_fulkerson(self, zrodlo, cel):
        """
        Algorytm Forda-Fulkersona do obliczania maksymalnego przepływu.
        """
        max_przeplyw = 0

        while True:
            odwiedzone = set()
            przeplyw = self.dfs(zrodlo, cel, float('inf'), odwiedzone)
            
            if przeplyw == 0:
                break
            max_przeplyw += przeplyw

        return max_przeplyw


# Przykład użycia
graf = Graf()
# Dodajemy krawędzie do grafu
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

# Zastosowanie algorytmu Forda-Fulkersona
zrodlo = graf.wezly["A"]
cel = graf.wezly["G"]

maksymalny_przeplyw = graf.ford_fulkerson(zrodlo, cel)
print(f"Maksymalny przepływ: {maksymalny_przeplyw}")
