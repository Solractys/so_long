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

Progresso:

[X] Validar extensão .ber 
[X] Verificar formato retangular
[X] Validar caracteres permitidos
[X] Contar P / E / C
[X] Verificar paredes ao redor 
[ ] Flood fill para checar caminhos

[ ] Criar t_game
[ ] Guardar posição inicial do player

[ ] Iniciar MiniLibX
[ ] Criar janela
[ ] Carregar sprites
[ ] Renderizar mapa completo

[ ] Implementar hook de teclado
[ ] Função de movimento do player
[ ] Atualizar mapa após cada movimento
[ ] Contador de movimentos

[ ] Detectar vitória
[ ] Hook para ESC
[ ] Função de cleanup geral

[ ] Função de erro
[ ] Norminette
[ ] Testar mapas válidos e inválidos
