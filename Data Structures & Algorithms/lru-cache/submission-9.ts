class DataNode {
    key: number;
    value: number;
    prev: DataNode | null;
    next: DataNode | null;

    constructor (key: number, value: number) {
        this.key = key
        this.value = value

        this.prev = null
        this.next = null
    }
}

class LRUCache {
    private capacity: number
    private map: Map<number, DataNode>
    private head: DataNode
    private tail: DataNode

    constructor(capacity: number) {
        this.capacity = capacity
        this.map = new Map<number, DataNode>()

        //Dummy nodes
        this.head = new DataNode(0, 0)
        this.tail = new DataNode(0, 0)
        
        this.head.next = this.tail
        this.tail.prev = this.head
    }

    private removeNode(node: DataNode): void {
        node.prev.next = node.next
        node.next.prev = node.prev
    }

    private insertAtHead(node: DataNode): void {
        this.head.next.prev = node
        node.next = this.head.next

        this.head.next = node
        node.prev = this.head
    }

    get(key: number): number {
        if(!this.map.has(key)) return -1

        const node = this.map.get(key)

        this.removeNode(node)
        this.insertAtHead(node)

        return node.value
    }

    put(key: number, value: number): void {
        if(this.map.has(key)) {
            const node = this.map.get(key)

            node.value = value

            this.removeNode(node)
            this.insertAtHead(node)
                    
        }
        else {
            if(this.map.size >= this.capacity) {
                const lruNode = this.tail.prev

                this.map.delete(lruNode.key)
                this.removeNode(lruNode)
            }

            const newNode = new DataNode(key, value)

            this.insertAtHead(newNode)
            this.map.set(key, newNode)
        }
    }
}
