void setup(){
    Serial.begin(115200);
    delay(10);
}

void loop(){
    bool recibido = false;
    int numero = 0;
    if(Serial.available()){
        numero = Serial.parseInt();
        recibido=true;
    }

    if(recibido){
        int numeros[numero];
        int index_final=0;
        for(int i = numero-1; i > 0; i--){
            int divisores[numero];
            int index = 0;
            for(int j = numero - 1; j>0;j--){
                if(i%j==0){
                    divisores[index]=j;
                    index++;
                }
            }
            if(index<=2){
                numeros[index_final]=i;
                index_final++;
            }
        }
        Serial.print(numeros[index_final-1]);
        for(int x=index_final-2;x>=0;x--){
            Serial.print(", ");
            Serial.print(numeros[x]);  
        }
        Serial.println();
    }
}
