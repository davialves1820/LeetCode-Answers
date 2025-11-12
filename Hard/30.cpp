class Solution {

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;

        // Caso base: se o vetor de palavras estiver vazio, não há nada a procurar
        if (words.empty()) return result;

        int wordLen = words[0].size();       // Tamanho fixo de cada palavra
        int wordCount = words.size();        // Quantas palavras existem em 'words'
        int totalLen = wordLen * wordCount;  // Tamanho total da concatenação esperada
        int n = s.size();                    // Tamanho da string principal

        // Se a string for menor que a concatenação esperada, é impossível conter todas
        if (n < totalLen) return result;

        // Cria um mapa com a contagem de cada palavra em 'words'
        unordered_map<string, int> wordMap;
        for (auto &w : words)
            wordMap[w]++;

        // Existem 'wordLen' possíveis pontos de início (offsets)
        // porque as palavras podem começar em diferentes posições dentro da string
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> window;  // Mapa de palavras dentro da janela atual
            int left = i;                       // Início da janela
            int count = 0;                      // Quantas palavras válidas temos até agora

            // Percorremos a string pulando de palavra em palavra
            for (int right = i; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);  // Extrai a palavra atual

                if (wordMap.count(word)) {  // Palavra está em 'words'
                    window[word]++;         // Adiciona ao mapa da janela
                    count++;                // Incrementa a contagem de palavras válidas

                    // Se a palavra aparecer mais vezes do que deveria:
                    // precisamos mover o início da janela (left)
                    while (window[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;  // Remove a palavra que saiu da janela
                        left += wordLen;     // Avança o início da janela
                        count--;             // Diminui o número de palavras válidas
                    }

                    // Se a janela contém exatamente todas as palavras uma vez
                    // adicionamos o índice inicial dessa substring à resposta
                    if (count == wordCount)
                        result.push_back(left);
                } 
                else {  
                    // Palavra inválida (não faz parte de 'words'):
                    // limpamos tudo e recomeçamos depois dela
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }

};
