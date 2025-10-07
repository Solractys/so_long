Organização do projeto:

Ideia: Jogo 2d em C usando a MiniLibX. Será um clone do Zelda bem minimalista.
        Os sprites serão feitos do zero, assim como as animações. Os coletáveis
        serão partes da triforce. Pegando as três partes a porta de saída será
        aberta. Quanto ao bonus, os inimigos podem ser Octoroks. Um hit será o
        suficiente pro player perder o jogo.

Pontos importantes:

Mapa: o programa receberá um mapa com extensão ".ber" e deve ser interpretado.
        Até aqui tudo bem, o que me preocupa é a validação desse mapa. O mapa deve ter um
        caminho válido para completar o jogo, se não houver um caminho válido o mapa também
        é invalidado. Além disso o mapa deve conter 4 elementos: 0 (espaços livres), C (Coletáveis),
        P (posição inicial do player), E (saída). Não foi falado quanto a inicial que servirá para os
        inimigos. O mapa só é válido se contiver todos esses elementos.
Gerenciamento Gráfico: Utilizando a MiniLibX a nossa janela deve ser flexível (pode ser minimizada, maximizada e fechada de
        forma limpa). Além disso, pressionar ESC deve fechar o jogo de forma limpa mostrando um "Error\n" e o uso de imagens
        da MiniLibX é obrigatório.
Sobre a mecanica do jogo:
        As teclas de movimento serão WASD, o player não deve se mover através das paredes, cada movimento deve ser contabilizado
        e mostrado na tela. O objetivo principal é coletar todos os coletáveis e sair do jogo.

Estratégias de desenvolvimento:

Primeira Parte: Análise e Validação do Mapa:

    1.1. Verificação do Arquivo e Extensão:
        - O programa deve aceitar um único argumento.
        - Validar se o argumento possui a extensão ".ber".
    1.2. Leitura do Mapa:
        - Abrir e ler o arquivo .ber.
        - Armazenar o conteúdo em uma matriz 2D (ex: char **map).
    1.3. Validação de Formato e Paredes:
        - Checar se o mapa é retangular.
        - Verificar se o mapa é completamente cercado por paredes ('1').
    1.4. Validação de Conteúdo:
        - Procurar por caracteres inválidos (diferentes de '0', '1', 'C', 'P', 'E').
        - Garantir que há exatamente um 'P', um 'E' e pelo menos um 'C'.
    1.5. Algoritmo de Caminho Válido:
        - Implementar um algoritmo de pathfinding (como flood fill, BFS ou DFS) a partir da posição 'P'.
        - O algoritmo deve confirmar que é possível alcançar todos os coletáveis ('C') e a saída ('E'). Se algum for inalcançável, o mapa é inválido.
