disp('!--') %comentario de varias lineas
disp('-Comienza la prueba del sumador:') %el guio produce titulo
disp('--|>')
x=[-2 -1 0 1 2];
y=[0 1 2 3 4 5];
aciertos=0;
for i=1:length(x)
    if(suma(x(i),y(i))==(x(i)+y(i)))
        resultado='Correcto';
        aciertos=aciertos+1;
    else
        resultado='Incorrecto';
    endif
    %comentario de una linea
    printf("Comment := >> suma(%d, %d)=%d%s\n", x(i), y(i), suma(x(i), y(i)), resultado)
end
printf("Grado := >>%d", round(aciertos/length(x)*10)) %calificacion