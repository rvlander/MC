import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=funqui(null,new double[][][]{colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(20))});

System.out.println("A=");
printMatrix(A);
System.out.println();
}
public static double[][] funqui(MCJOutputArg[] oargs,double[][] A){
double[][] B= new double[0][0];
B=add(A,matrixFromDouble(2));

if(oargs !=null){
if(oargs.length>0)oargs[0].val=B;
}
return B;
}

}
