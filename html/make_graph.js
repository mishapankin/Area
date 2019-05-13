var elt = document.getElementById('calculator');
var calculator = Desmos.GraphingCalculator(elt);

calculator.setExpression({id:'graph1', latex: expr1});
calculator.setExpression({id:'graph2', latex: expr2});
calculator.setExpression({id:'graph3', latex: expr3});

calculator.setExpression({id:'a', latex: expr_a});
calculator.setExpression({id:'b', latex: expr_b});