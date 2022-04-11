## Adicionando dependências nos projetos

Vamos adicionar o GLAD e o GLFW em cada projeto. Para tal você deve:

- Adicionar as pastas "include" de cada uma das dependências
- Adicionar no linker, o binário compilado (.lib) do glfw


Então: 

- Clique com o botão direito no projeto e depois em propriedades
- Navegue até a aba "C/C++" e então "General"
- No primeiro item, "Additional Include Directories", adicione o seguinte: $(SolutionDir)Dependencies\GLFW\include;$(SolutionDir)Dependencies\GLAD\include
- Pronto!

Agora:

- Navegue até "Linker" e então "Input"
- No primeiro item, "Additional Dependencies", inclua o seguinte: glfw3.lib
- Agora, vá até "Linker" e "General"
- No item, "Additional Library Directories" adicione: $(SolutionDir)Dependencies\GLFW\lib-vc2022
- Pronto!


## Fim

Feito isso, você deve ser capaz de criar um novo arquivo .cpp e incluir as bibliotecas necessárias para o OpenGL.

- #include <GLFW/glfw3.h>
- #include <glad/glad.h>
