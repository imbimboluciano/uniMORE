package oop.Generics.Shop;

import java.util.Objects;

public class Product {

    public String description;
    public Product() {
        this.description = null;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Product)) return false;
        Product product = (Product) o;
        return Objects.equals(description, product.description);
    }

    @Override
    public int hashCode() {
        return Objects.hash(description);
    }

    @Override
    public String toString() {
        return "Product{" +
                "description='" + description + '\'' +
                '}';
    }
}
