## Lista de Exercícios 1 – Processamento Gráfico
### Introdução à OpenGL Moderna – Shaders & Buffers

---
**1 - O que é a GLSL? Quais os dois tipos de shaders são obrigatórios no pipeline programável 
da versão atual que trabalhamos em aula e o que eles processam?**

GLSL (OpenGL Shading Language) é uma linguagem de programação imperativa baseada em C e C++. 
É utilizada por desenvolvedores para ter controle mais direto do pipeline gráfico do OpenGL
sem ter que utilizar linguagens de mais baixo nível, como assembly.

Os principais shaders utilizados no pipeline são o Vertex shader e o Fragment shader.

- Vertex shader - processa os vértices individuais, se preocupa com dados posicionais
- Fragment shader - processa os pixels, preocupa-se com o cálculo do output de cor dos pixels

---
**2 - O que são primitivas gráficas? Como fazemos o armazenamento dos vértices na OpenGL?**

Primitivas gráficas são "dicas" que passamos ao OpenGL sobre a forma como queremos renderizar os dados.
Ex. pontilhado? uma única linha? uma coleção de triângulos?

Armazenamos dados dos vértices direto na memória da GPU. Para isso, utilizamos VBO (vertex buffer objects), 
um objeto buffer que abstrai e facilita o gerenciamento dessa memória.

---
**3 - Explique o que é VBO, VAO e EBO, e como se relacionam.**

São estruturas que hajem como handlers da memória da GPU. Como a GPU só trabalha com dados que estão na
sua memória, precisamos dessas estruturas para poder manipular.

VBO (vertex buffer objects) - armazena os dados dos vértices
VAO (vertex array objects) - handle para VBOs, um VAO pode armazenar um ou mais VBOs
EBO (element buffer objects) - buffer que, também armazena dados dos vértices, mas permite indexar os valores de modo que seja mais simples de manipular multiplas formas (o início de um é o começo de outro)

---
**5 - Faça o desenho de 2 triângulos na tela. Desenhe eles:**

a. Apenas com o polígono preenchido

![](https://i.imgur.com/fArcvZk.png)

b. Apenas com contorno

![](https://i.imgur.com/cYNI7EO.png)

c. Apenas como pontos

![](https://i.imgur.com/4ZIx2Q5.png)

d. Com as 3 formas de desenho juntas

---
**6 - Faça o desenho de um círculo na tela, utilizando a equação paramétrica do círculo para
gerar os vértices. Depois disso:**

a. Um octágono

![](https://i.imgur.com/9UqSF0a.png)

b. Um pentágono

![](https://i.imgur.com/0l9ru3D.png)

c. Um pac-man

![](https://i.imgur.com/ucY2M34.png)

d. Uma fatia de pizza

![](https://i.imgur.com/VuQVwny.png)

---
**7 - Desenhe uma espiral:**

![](https://i.imgur.com/87RXHzU.png)
