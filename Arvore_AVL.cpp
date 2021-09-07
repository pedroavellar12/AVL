

class T{
    
    struct No{
        int valor;
        No* esq;
        No* dir;
        int altura;
    };
    No* raiz;

    void deletarArvore(No* T){
        if(T == NULL){
            return;
        }
        deletarArvore(T->esq);
        deletarArvore(T->dir);
        delete T;
    }

    No* insere(int x, No* T){
        if(T == NULL){
            T = new No;
            T->valor = x;
            T->altura = 0;
            T->esq = T->dir = NULL;
        } else if(x < T->valor){
            T->esq = insere(x, T->esq);
            if(altura(T->esq) - altura(T->dir) == 2){
                if(x < T->esq->valor){
                    T = rotateRR(T);
                } else{
                    T = rotateRL(T);
                }
            }
        } else if(x > t->valor){
            T->dir = insere(x, T->dir);
            if(altura(T->dir) - altura(T->esq) == 2){
                if(x > T->dir->valor){
                    T = rotateLL(T);
                } else{
                    T = rotateLR(T);
                }
            }
        }
        T->altura = max(altura(T->esq), altura(T->dir))+1;
        return T;
    }

    No* rotateRR(No* T){
        No* U = T->esq;
        T->esq = U->dir;
        U->dir = T;
        T->altura = max(altura(T->esq), altura(T->dir))+1;
        U->altura = max(altura(U->esq), T->altura)+1;
        return U;
    }

    No* rotateLL(No* T){
        No* U = T->dir;
        T->dir = U->esq;
        U->esq = T;
        T->altura = max(altura(T->esq), altura(T->dir))+1;
        U->altura = max(altura(U->dir), T->altura)+1;
        return U;
    }

    No* rotateLR(No* T){
        T->dir = rotateRR(T->esq);
        return rotateLL(T);
    }

    No* rotateRL(No* T){
        T->esq = rotatL(T->dir);
        return rotateRR(T);
    }

    No* buscaMin(No* T){
        if(T == NULL){
            return NULL;
        } else if(T->esq == NULL){
            return T;
        } else{
            return Min(T->esq);
        }
    }

    No* buscaMax(No* T){
        if(T == NULL){
            return NULL;
        } else if(T->dir == NULL){
            return T;
        } else{
            return Min(T->dir);
        }
    }

    No* remove(int x, No* T){
        No* aux;

        //Elemento não encontrado
        if(T==NULL){
            return NULL;
        } else if(x < T->valor){   //Procurando o elemento
            T->esq = remove(x, T->esq);
        } else if(x > T->valor){
            T->dir = remove(x, T->dir);
        } else if(T->esq && T->dir){  //Elemento encontrado com 2 filhos
            aux = Min(T->dir);
            T->valor = aux->valor;
            T->dir = remove(T->valor, T->dir);
        } else{    //Elemento com 1 ou 0 filho
            aux = T;
            if(T->esq == NULL){
                T = T->dir;
            } else if(T->dir == NULL){
                T = T->esq;
            }
            delete aux;
        }

        if(T==NULL){
            return T;
        }

        T->altura = max(altura(T->esq), altura(T->dir))+1;

        //Se No está desbalanceado:
        //Se No esq for deletado
        if(altura(T->esq) - altura(T->dir) == 2){
            //Rotação LL
            if(altura(T->esq->esq) - altura(T->esq->dir) == 1){
                return rotateLL(T);
            } else{ //Rotação LR
                return rotateLR(T);
            }

        //Se No dir for deletado
        }else if(altura(T->esq->esq) - altura(T->esq->dir) == 1){
            //Rotação RR
            if(altura(T->dir->dir) - altura(T->dir->esq) == 1){
                return rotateRR(T);
            } else{ // Rotação RL
                return rotateRL(T);
            }
        }

        return T;
    }

    int altura(No* T){
        return (T==NULL ? 1 : T->altura);
    }

    int fatBalance(No* T){
        if(T==NULL){
            return 0;
        } else{
            return (altura(T->esq) - altura(T->dir));
        }
    }

    void inorder(No* T){
        if(T==NULL){
            return;
        }
        inorder(T->esq);
        cout << T->valor << " ";
        inorder(T->dir);
    }

    void preorder(No* T){
        if(T==NULL){
            return;
        }
        cout << T->valor << " ";
        inorder(T->esq);
        inorder(T->dir);
    }

    void posorder(No* T){
        if(T==NULL){
            return;
        }
        inorder(T->esq);
        inorder(T->dir);
        cout << T->valor << " ";
    }

    public:
    T(){
        raiz = NULL;
    }

    void insere(int x){
        raiz = insere(x, raiz);
    }

    int remove(int x){
        raiz = remove(x, raiz);
    }

    void display(){
        inorder(raiz);
        cout << endl;
    }

};





