# Status técnico — Shadow Granny

## O que já existe
- Aplicativo Android com interface preta/roxa.
- Projeto Gradle com alvo ARM64 (`arm64-v8a`).
- Biblioteca nativa `libshadow.so` compilada pelo NDK via `jni/Android.mk`.
- Ponte JNI para os botões Freeze Granny, God Mode e Speed.
- Os estados dos controles são mantidos em variáveis nativas e aparecem no Logcat.

## Limitação importante
Os botões ainda são **demonstrações de interface**. Este app não injeta código no processo do Granny, não localiza instâncias Unity e não altera a jogabilidade. Para transformar os botões em funções reais, seria necessário confirmar a versão exata do jogo, validar a estrutura IL2CPP em execução e implementar/testar a integração de forma específica para essa versão. Um RVA do dump não é um endereço absoluto e pode mudar entre builds.

## Segurança e compatibilidade
- Não publique APKs do jogo, `libil2cpp.so`, `global-metadata.dat` ou dumps proprietários neste repositório.
- Compile e teste primeiro a interface isolada.
- Em caso de crash, remova qualquer integração experimental e confira o Logcat.
