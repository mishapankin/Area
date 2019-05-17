var elt = document.getElementById('calculator');
var options = { border: false };
var calculator = Desmos.GraphingCalculator(elt, options);

calculator.setExpression({id: 'graph1', latex: expr1});
calculator.setExpression({id: 'graph2', latex: expr2});
calculator.setExpression({id: 'graph3', latex: expr3});

calculator.setExpression({id: 'a', latex: expr_a});
calculator.setExpression({id: 'b', latex: expr_b});

calculator.setExpression({id: 'area', latex: expr_int});