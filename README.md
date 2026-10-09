# Shadow Granny Android — ARM64 scaffold

Projeto de estudo para Android ARM64, pensado para edição no celular com AIDE.

## Estado atual

**Isto é um protótipo, não um mod funcional ainda.** Os controles Freeze Granny, God Mode e Speed apenas guardam o estado ligado/desligado no código nativo. Eles ainda não alteram a Granny nem a jogabilidade.

O dump indica metadados como o campo `EnemyAIGranny.freeze` e o método `grannyFreeze()`, mas offsets/RVAs dependem da versão exata do jogo e não devem ser tratados como endereços absolutos.

## Arquivos

- `jni/shadow.cpp`: camada JNI/C++ com estados de exemplo.
- `jni/Android.mk` e `jni/Application.mk`: configuração do NDK para `arm64-v8a`.
- `app/src/main/java/com/shadow/granny/NativeBridge.java`: ponte Java/JNI.
- `app/src/main/java/com/shadow/granny/MainActivity.java`: interface demonstrativa preta e roxa.

## Compilação

Este repositório contém os fontes-base; ainda não é um projeto Android completo pronto para gerar APK. No AIDE, crie um projeto Android com suporte a C/C++/NDK e copie os arquivos para os caminhos indicados. Configure o projeto para compilar `jni/Android.mk` e inclua as classes Java no pacote `com.shadow.granny`.

Não inclua o APK do jogo, bibliotecas proprietárias ou arquivos do jogo no repositório público.
