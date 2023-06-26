export class LinkedListNode {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}
export class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    pushFront(value) {
        const newNode = new LinkedListNode(value);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.length = this.length + 1;
    }
    pushBack(value) {
        const newNode = new LinkedListNode(value);
        if (this.tail === null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            newNode.prev = this.tail;
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.length = this.length + 1;
    }
    popFront() {
        if (this.head === null) {
            return null;
        }
        const frontValue = this.head.value;
        if (this.head === this.tail) {
            this.head = null;
            this.tail = null;
        }
        else {
            this.head = this.head.next;
            this.head.prev = null;
        }
        this.length = this.length - 1;
        return frontValue;
    }
    popBack() {
        if (this.tail === null) {
            return null;
        }
        const backValue = this.tail.value;
        if (this.head === this.tail) {
            this.head = null;
            this.tail = null;
        }
        else {
            this.tail = this.tail.prev;
            this.tail.next = null;
        }
        this.length = this.length - 1;
        return backValue;
    }
    getFront() {
        return this.head !== null ? this.head.value : null;
    }
    getBack() {
        return this.tail !== null ? this.tail.value : null;
    }
    getLength() {
        return length;
    }
}
