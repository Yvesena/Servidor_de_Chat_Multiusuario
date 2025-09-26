
# 🗨️ Servidor de Chat Multiusuário (TCP)

Projeto final da disciplina **LPII – Programação Concorrente (C/C++)**.  
Implementa um **servidor de chat em rede** com múltiplos clientes simultâneos, utilizando **threads**, **monitores** e a biblioteca de **logging thread-safe libtslog**.

---

## 📋 Funcionalidades

- Servidor TCP concorrente que aceita múltiplos clientes ao mesmo tempo.
- Cada cliente é atendido por **uma thread dedicada**.
- **Broadcast**: toda mensagem enviada por um cliente é retransmitida a todos os demais conectados.
- **Logging concorrente** com `libtslog`: eventos (entrada, saída e mensagens) são gravados em arquivo de log sem race conditions.
- Proteção de estruturas compartilhadas (lista de clientes) via **monitor** (mutex + condition variables).
- Cliente CLI (linha de comando) para conectar e conversar em tempo real.



# Servidor_de_Chat_Multiusuario — Etapa 1

## Etapa 1: Biblioteca de Logging Concorrente

Esta etapa implementa uma biblioteca de logging thread-safe em C, capaz de registrar mensagens de múltiplas threads de forma segura em um arquivo de log.

### Como compilar

Abra o terminal na pasta `Projeto_Chat` e execute: 
make

### Como executar o teste

Após compilar, execute o teste com:
./test_logging


O programa irá criar várias threads que escrevem mensagens simultaneamente no arquivo `app.log`.

### Verificando o resultado

Após a execução, confira o arquivo `app.log` na pasta do projeto.  
Você verá as mensagens escritas por diferentes threads, demonstrando que a biblioteca de logging funciona corretamente em ambiente concorrente.
