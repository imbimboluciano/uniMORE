import numpy as np

from datasets import gaussians_dataset, people_dataset

from utils import people_visualization
from utils import people_visualize_prediction
from utils import plot_pegasos_margin

from svm import SVM

from sklearn.svm import SVC

#np.random.seed(191090)

def main_people():
    """ Main function """

    #x_train, y_train, x_test, y_test = gaussians_dataset(2, [100, 150], [[1, 3], [-4, 8]], [[2, 3], [4, 1]])
    X_img_train, x_train, y_train, X_img_test, x_test, y_test = people_dataset('data/svm')
    people_visualization(X_img_train, y_train)

    svm_alg = SVM(n_epochs=100, lambDa= 0.001, use_bias=True)

    # train
    svm_alg.fit_gd(x_train, y_train, verbose=True)

    # test
    predictions = svm_alg.predict(x_test)

    accuracy = float(np.sum(predictions == y_test)) / y_test.shape[0]
    print('Test accuracy: {}'.format(accuracy))

    people_visualize_prediction(X_img_test, y_test, predictions)

def main_gaussian():

    x_train, y_train, x_test, y_test = gaussians_dataset(2, [100, 150], [[1, 3], [-4, 8]], [[2, 3], [4, 1]])

    svm_alg = SVM(n_epochs=100, lambDa= 0.001, use_bias=True)

    # train
    svm_alg.fit_gd(x_train, y_train, verbose=True)

    # test
    predictions = svm_alg.predict(x_test)

    accuracy = float(np.sum(predictions == y_test)) / y_test.shape[0]
    print('Test accuracy: {}'.format(accuracy))

    plot_pegasos_margin(x_test, y_test, svm_alg)

def main_people_scikit():
    """ Main function """

    #x_train, y_train, x_test, y_test = gaussians_dataset(2, [100, 150], [[1, 3], [-4, 8]], [[2, 3], [4, 1]])
    X_img_train, x_train, y_train, X_img_test, x_test, y_test = people_dataset('data/svm')
    people_visualization(X_img_train, y_train)

    clf = SVC(C = 0.8, kernel='linear') # accuracy = 0.83826
    clf = SVC(C = 0.8, kernel='poly') # accuracy = 0.95255
    clf = SVC(C = 0.8, kernel='rbf') # accuracy = 0.94744

    clf.fit(x_train,y_train)

    # test
    predictions = clf.predict(x_test)

    accuracy = float(np.sum(predictions == y_test)) / y_test.shape[0]
    print('Test accuracy: {}'.format(accuracy))

    people_visualize_prediction(X_img_test, y_test, predictions)


# entry point
if __name__ == '__main__':
    #main_gaussian()
    #main_people()
    main_people_scikit()
