/**
 * @param {number[]} arr
 * @return {number}
 */

var maxChunksToSorted = function (arr) {
  let n = arr.length;
  let prefixSumModel = [0];
  for (let i = 1; i < arr.length; i++)
    prefixSumModel.push(prefixSumModel[prefixSumModel.length - 1] + i);
  let sum = 0;
  let count = 0;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
    if (sum === prefixSumModel[i]) count += 1;
  }
  return count;
};

//let arr = [2, 0, 1];
//arr = [1, 0, 2, 3, 4];
arr = [2, 1, 3, 0, 4, 6, 5];
console.log(maxChunksToSorted(arr));
