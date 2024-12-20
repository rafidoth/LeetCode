package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func bfs(root *TreeNode) {
	if root == nil {
		return
	}

	var queue []*TreeNode
	queue = append(queue, root)
	var level = 0
	for len(queue) > 0 {
		var n = len(queue)
		var currentLevelNodes []*TreeNode
		for i := 0; i < n; i++ {
			currentNode := queue[0]
			queue = queue[1:]
			currentLevelNodes = append(currentLevelNodes, currentNode)
			if currentNode.Left != nil {
				queue = append(queue, currentNode.Left)
			}
			if currentNode.Right != nil {
				queue = append(queue, currentNode.Right)
			}
		}

		if level%2 != 0 {
			var left_pointer, right_pointer = 0, len(currentLevelNodes) - 1
			for left_pointer < right_pointer {
				var temp = currentLevelNodes[left_pointer].Val
				currentLevelNodes[left_pointer].Val = currentLevelNodes[right_pointer].Val
				currentLevelNodes[right_pointer].Val = temp
				right_pointer--
				left_pointer++
			}
		}

		level++
	}
}

func main() {
}
