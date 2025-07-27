# Ollama
Ollama is a way to host AI locally. 
## Installing Ollama
* Command: ```curl -fsSL https://ollama.com/install.sh | sh```
* check http://localhost:11434 for **ollama is running**
## Installing AI models locally
* Command: ```ollama pull <model name>```
    * Example: llama3
* ```ollama run <model name>```
* chat in the terminal
## Automatic 1111
```sh
sudo apt install -y make build-essential libssl-dev zlib1g-dev \
libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncurses5-dev \
libncursesw5-dev xz-utils tk-dev libffi-dev liblzma-dev python-openssl git
```