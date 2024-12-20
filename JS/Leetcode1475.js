/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function (prices) {
  // for each prices[i] search from i+1 to last index
  // whenever we get prices[j] smaller than prices[i]
  // update prices[i]
  return prices.map((price, indx) => {
    let j;
    let gotDiscount = false;
    for (j = indx + 1; j < prices.length; j++) {
      if (prices[j] <= price) {
        gotDiscount = true;
        break;
      }
    }
    if (gotDiscount) price -= prices[j];
    return price;
  });
};
