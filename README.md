# 📋 Sistema de Gerenciamento de Estoque
[![Badge Concluído](https://img.shields.io/badge/status-em%20Concluído-yellow)]()
[![Licença](https://img.shields.io/badge/license-MIT-blue)]()

## 📌 Informações do Projeto

**🏫 Universidade:** Universidade Federal do Piauí - Campus Senador Helvídio Nunes de Barros  
**🎓 Curso:** Bacharelado em Sistemas de Informação  
**📚 Disciplina:** Algoritmos e Programação I  
**👩‍🏫 Professor(a):** Dra. Alcilene Dalília de Sousa  

**👥 Equipe:**
- Mayan
- Lyan
- Betânia
- Allana
- Débora

## 🚀 Descrição do Projeto

Sistema de gerenciamento de estoque desenvolvido em C que permite:  
🛒 Cadastrar | 🔍 Buscar | ✏️ Editar | 📜 Listar produtos | 🗑️ Remover 

## 📂 Estrutura do Projeto

```
projeto_estoque/
├── 📄 main.c                 # Arquivo principal
├── 📂 screenshots            # Capturas de tela
├── 📂 modules/
│   ├── 📄 funcoes_estoque.c  # Funções do estoque
│   ├── 📄 funcoes_estoque.h  # Cabeçalhos
│   ├── 📄 modulo_print.c     # Funções de exibição
│   └── 📄 modulo_print.h     # Cabeçalhos
└── 📄 README.md              # Documentação do projeto
```

## 💻 Como Compilar e Executar

### 🔧 Compilação e Execução
```bash
#Windows
gcc main.c modules/funcoes_estoque.c modules/modulo_print.c -o estoque.exe
.\estoque.exe
```
## ✨ Funcionalidades

1. **📝 Cadastrar Produto**
   - ✅ Verifica IDs duplicados
   - ⚠️ Limite de 100 produtos

2. **📋 Listar Produtos**
   - 🔄 Ordenado por ID
   - 📊 Exibe todos os atributos

3. 🔍 Buscar Produto
   - 🔎 Por ID
   - 📌 Exibe detalhes completos

4. ✏️ Editar Produto
   - 🔄 Atualiza individualmente:
     - #️⃣ ID
     - 🔤 Nome
     - 💲 Preço
     - 🧮 Quantidade

5. 🗑️ Remover Produto
   - ⚠️ Confirmação antes de excluir
   - 🔄 Reorganiza a lista automaticamente


## 🖼️ Demonstração Visual

<div align="center">
  <h3>🎛️ Menu Principal</h3>
  <img src="./screenshots/menu.png" alt="Menu do Sistema" width="400">
  <p><em>Interface principal com navegação completa</em></p>
  
  <h3>📝 Cadastro de Produtos</h3>
  <img src="./screenshots/cadastro.png" alt="Tela de cadastro" width="400">
  <p><em>Formulário com validação de campos obrigatórios</em></p>
</div>

## 🛠️ Tecnologias Utilizadas

- **🔢 Vetores** para armazenamento
- **📊 Estruturas** para organização dos dados
- **🔄 Algoritmos** de ordenação e busca

## 🐛 Bugs Conhecidos

| Problema | Gravidade | Descrição |
|----------|-----------|-----------|
| 📛 Nomes longos | ⚠️ Médio | Nomes > 49 caracteres causam problemas |
| 💰 Valores negativos | ⚠️ Baixo | Aceita preços/quantidades negativas |
| 🖥️ Portabilidade | ⚠️ Alto | Funciona melhor no Windows |
