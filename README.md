# 🏓 Pong em C++ (SFML 3)

Um clone moderno do clássico jogo arcade Pong, desenvolvido do zero utilizando **C++17** e a biblioteca multimídia **SFML 3**.

Este projeto foi construído com foco em boas práticas de programação, aplicando uma arquitetura Orientada a Objetos limpa para separar as responsabilidades da *Engine*, dos Atores e da Física, além de utilizar conceitos fundamentais de desenvolvimento de jogos.

## ✨ Funcionalidades e Aprendizados

* **Game Loop Customizado:** Processamento de eventos, atualização de lógica e renderização estruturados profissionalmente.
* **Independência de Framerate (Delta Time):** Movimentação fluida e consistente baseada no tempo real (`dt`), independente da potência do processador.
* **Colisão AABB (Axis-Aligned Bounding Box):** Detecção precisa de colisão entre a bola, as raquetes e os limites da tela, com resolução de penetração para evitar bugs de física.
* **Multiplayer Local:** Suporte para dois jogadores no mesmo teclado.
* **Sistema de Placar:** Carregamento de fontes dinâmicas (`.ttf`) e renderização de Interface de Usuário (UI) em tempo real.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (Padrão C++17)
* **Biblioteca Gráfica/Áudio:** SFML 3 (Simple and Fast Multimedia Library)
* **Build System:** CMake
* **Compilador Recomendado:** GCC / MinGW-w64 (via MSYS2 no Windows) ou nativo no Linux.

## 🏗️ Arquitetura do Projeto

O código foi dividido seguindo princípios de separação de responsabilidades (Arquitetura Orientada a Objetos com separação em `.hpp` e `.cpp`):

* `main.cpp`: Ponto de entrada enxuto, responsável apenas por instanciar e rodar o jogo.
* `Game`: O "Motor" central. Gerencia a janela, o *Game Loop*, instanciação dos objetos e a verificação de regras globais (colisões entre entidades e placar).
* `Paddle`: Classe responsável pela lógica, renderização e movimentação das raquetes dos jogadores.
* `Ball`: Classe autônoma que gerencia sua própria velocidade, direção e colisões com o teto/chão.

## 🎮 Como Jogar

* **Player 1 (Esquerda):** Teclas `W` (Cima) e `S` (Baixo)
* **Player 2 (Direita):** Setas Direcionais `↑` (Cima) e `↓` (Baixo)
* O objetivo é fazer a bola passar pela raquete do adversário. O placar é atualizado automaticamente na parte superior da tela.

## ⚙️ Como Compilar e Rodar

### Pré-requisitos
Certifique-se de ter o **CMake** (mínimo 3.20) e um compilador C++ configurado em sua máquina. Para Windows, recomenda-se o MSYS2 para baixar a biblioteca SFML 3:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-sfml
```
### Passos para Build

1. **Clone este repositório:**
   ```bash
   git clone [https://github.com/OyudiF/SimplePong.git](https://github.com/OyudiF/SimplePong.git)
   ```

2. **Navegue até a pasta do projeto:**
    ```bash
    cd pong-cpp-sfml
    ```

3. **Crie uma pasta de build e configure o CMake:**
    ```bash
    mkdir build && cd build
    cmake ..
   ```
4. **Compile o projeto:**
    ```bash
   cmake --build .
   ```
5. **Execute o jogo:**
    ```bash
   ./MeuJogo
   ```
Nota: Certifique-se de que o arquivo de fonte arial.ttf esteja configurado no seu CMakeLists.txt para ser copiado para o diretório de build, ou coloque-o manualmente na mesma pasta do executável para que o placar seja carregado corretamente.
