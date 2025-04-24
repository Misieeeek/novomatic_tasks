#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void add_question(std::string& s);
void ask_question(std::string& s);

std::vector<std::string> questions(0);

int main() {
  std::string input;
  std::cout
      << "Witaj w szukajka.pl!\nWprowadz nowe pytanie (add: [Twoje pytanie])\n"
         "lub zadaj pytanie (ask: [Twoje pytanie])\('q' aby wyjsc)\n> ";
  while (getline(std::cin, input) && !(input == "q")) {

    std::size_t found;
    if ((found = input.find("ask: ")) != std::string::npos)
      ask_question(input);
    else if ((found = input.find("add: ")) != std::string::npos)
      add_question(input);
    else
      std::cout << "Nieznane polecenie. Uzyj 'add: ' lub 'ask: '.\n";
    std::cout << "> ";
  }
}

void add_question(std::string& s) {
  if (s.length() == 5)
    std::cout << "Pytanie jest puste!\n";
  else
    questions.push_back(s.substr(5));
}

void ask_question(std::string& s) {
  s = s.substr(5);
  for (const auto& q : questions) {
    size_t len = 0;
    size_t min_len = std::min(s.length(), q.length());
    while (len < min_len && s[len] == q[len])
      ++len;
    std::string lcp = s.substr(0, len);
    if (len == s.length())
      std::cout << "Result: " << q << "\n";
  }
}
