# Shadow Granny Android — menu ARM64

Projeto Android de estudo com interface Shadow preta/roxa, ponte JNI e alvo nativo ARM64 (`arm64-v8a`).

## Estado atual

**A interface e a estrutura de compilação estão no repositório; os efeitos no jogo ainda não estão implementados.** Os botões Freeze Granny, God Mode e Speed alteram apenas estados demonstrativos no código nativo. Este aplicativo não injeta a biblioteca no processo de Granny nem altera a jogabilidade.

Os nomes de campos/métodos observados no dump, como `EnemyAIGranny.freeze` e `grannyFreeze()`, não bastam sozinhos para implementar uma função estável: offsets/RVAs dependem da versão exata do jogo e o acesso a instâncias Unity/IL2CPP precisa ser validado em execução.

## Estrutura

- `app/src/main/java/com/shadow/granny/MainActivity.java` — interface preta/roxa.
- `app/src/main/java/com/shadow/granny/NativeBridge.java` — ponte Java/JNI.
- `app/src/main/AndroidManifest.xml` — manifesto Android.
- `app/build.gradle`, `build.gradle`, `settings.gradle` — configuração Gradle.
- `jni/shadow.cpp` — biblioteca nativa C++ demonstrativa.
- `jni/Android.mk`, `jni/Application.mk` — compilação NDK para ARM64.
- `docs/STATUS-PT-BR.md` — estado técnico e limitações.

## Abrir no AIDE

Abra/importa o projeto Gradle no AIDE Pro. Se sua versão do AIDE não aceitar o projeto Gradle/NDK diretamente, crie um projeto Android com suporte a C/C++ e copie a pasta `app/src/main` e a pasta `jni`, mantendo o pacote Java `com.shadow.granny`.

## Importante

- O projeto ainda não gera um mod funcional para Granny; é a base da interface e da biblioteca nativa.
- Não adicione APK do jogo, `libil2cpp.so`, `global-metadata.dat` ou dumps proprietários a um repositório público.
- A compilação NDK de C/C++ para Android e o uso da JNI seguem a estrutura descrita na documentação oficial do Android NDK: https://developer.android.com/ndk/guides/
