void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int j = 0;
    for (int i = m; i < n + m; i++) {
        nums1[i] = nums2[j++];
    }

    for (int i = 1; i < n + m; i++) {

        int pivo = nums1[i]; // Pivô para salvar o elemento atual
        int j = i - 1; // j começa uma posição antes de i

        // Enquanto a posição antes do pivô conter um valor superior ou chegar ao fim do vetor
        while (j >= 0 && nums1[j] > pivo) { 
            
            nums1[j + 1] = nums1[j]; // Faz um reordenamento da esquerda para direita
            j--; // Decrementa j
        }

        nums1[j+1] = pivo; // O pivô é realocado para que antes dele não esteja nenhum valor superior
    }
}
