export interface BObject {
    equals(other: any): boolean;
    hashCode(): number;
}